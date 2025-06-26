---Opens a floating windo
---@param buf? integer buffer-ID of buffer to put in thw window
---@param w_percent? decimal width of floating window will be this * full width
---@param h_percent? decimal height of floating window will be this * full height
---@param opts any options to pass to nvim_open_win
local function open_floating_win(buf, w_percent, h_percent, opts)
  buf = buf or vim.api.nvim_create_buf(true, false)
  w_percent = w_percent or 0.8
  h_percent = h_percent or 0.8
  local default_opts = {
    relative = 'editor',
    row = (vim.o.lines - vim.o.lines * h_percent)/2,
    col = (vim.o.columns - vim.o.columns * w_percent)/2,
    width = math.floor(vim.o.columns * w_percent),
    height = math.floor(vim.o.lines * h_percent),
    style = 'minimal',
    border = 'rounded'
  }
  opts = vim.tbl_deep_extend('force', default_opts, opts or {})
  vim.api.nvim_open_win(buf, true, opts)
end

---@class TermState
---@field bufs integer[]
---@field last_used integer[]
---@field curr_buf_index integer
---@field win integer
local term_state = {
  bufs = { -1, -1, -1, -1 },
  last_used = { 1, 2, 3, 4 },
  curr_buf_index = 1,
  win = -1,
}

vim.api.nvim_create_user_command('Floaterminal', function(args_table)

  local is_new = false
  if args_table.args ~= '' then

    local operation = args_table.args

    if operation == 'next' then
      term_state.curr_buf_index = term_state.curr_buf_index + 1
      if term_state.curr_buf_index > 4 then
        term_state.curr_buf_index = 1
      end
    elseif operation == 'prev' then
      term_state.curr_buf_index = term_state.curr_buf_index - 1
      if term_state.curr_buf_index < 1 then
        term_state.curr_buf_index = 4
      end
    else
      error('invalid argument, use next or prev')
    end

    if not vim.api.nvim_buf_is_valid(term_state.bufs[term_state.curr_buf_index]) then
      term_state.bufs[term_state.curr_buf_index] = vim.api.nvim_create_buf(true, false)
      is_new = true
    end

    for index, value in ipairs(term_state.last_used) do
      if value == term_state.curr_buf_index then
        table.remove(term_state.last_used, index)
        break
      end
    end
    table.insert(term_state.last_used, 1, term_state.curr_buf_index)

    vim.api.nvim_set_current_buf(term_state.bufs[term_state.curr_buf_index])

  else

    for _ = 1, 4 do
      if not vim.api.nvim_buf_is_valid(term_state.bufs[term_state.last_used[1]]) then
        local invalid_buf_index = table.remove(term_state.last_used, 1)
        table.insert(term_state.last_used, 4, invalid_buf_index)
      end
    end

    if not vim.api.nvim_buf_is_valid(term_state.bufs[term_state.last_used[1]]) then
      term_state.bufs[term_state.last_used[1]] = vim.api.nvim_create_buf(true, false)
      is_new = true
    end

    open_floating_win(term_state.bufs[term_state.last_used[1]])

    term_state.win = vim.api.nvim_get_current_win()

  end

  if is_new then
    vim.cmd.term()
  end
  if vim.api.nvim_get_mode().mode == 'nt' then
    vim.api.nvim_feedkeys('a', 'n', true)
  end

end, { nargs = '?', desc = 'open the floaterminaaal' })


local oil_buf = -1

vim.api.nvim_create_user_command('Floateroil', function()
  local is_new = false
  if not vim.api.nvim_buf_is_valid(oil_buf) then
    oil_buf = vim.api.nvim_create_buf(true, false)
    is_new = true
  end

  open_floating_win(oil_buf)
  if is_new then
    vim.cmd('Oil')
  end

end, { desc = 'open the floateroil' })


local dev_log_buf = -1
vim.api.nvim_create_user_command('FloutterLog', function (args)
  local name = args.args
  if not vim.api.nvim_buf_is_valid(dev_log_buf) then
    dev_log_buf = vim.api.nvim_create_buf(true, false)
    vim.api.nvim_buf_set_name(dev_log_buf, name)
  end
  vim.keymap.set('n', '<F27>', '<cmd>q<CR>', { desc = 'close dev log', buffer = dev_log_buf })
  open_floating_win(dev_log_buf)
end, { desc = 'flutter dev log floating', nargs = 1 })
