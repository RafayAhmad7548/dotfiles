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

local term_state = {
  -1,
  -1,
  -1,
  -1,
  last_used = 1,
  win = -1,
}

vim.api.nvim_create_user_command('Floaterminal', function(table)
  -- TODO: update last_used buffer if it gets deleted

  local is_new = false
  if table.args ~= '' then

    local num = tonumber(table.args)
    if num < 1 or num > 4 then
      error('numbers from 1 to 4 allowed only')
    end
    if not vim.api.nvim_win_is_valid(term_state.win) then
      error('only specify arguments after opening the floaterminal')
    end

    if not vim.api.nvim_buf_is_valid(term_state[num]) then
      term_state[num] = vim.api.nvim_create_buf(true, false)
      is_new = true
    end

    term_state.last_used = num
    vim.api.nvim_set_current_buf(term_state[num])

  else

    if not vim.api.nvim_buf_is_valid(term_state[term_state.last_used]) then
      term_state[term_state.last_used] = vim.api.nvim_create_buf(true, false)
      is_new = true
    end

    open_floating_win(term_state[term_state.last_used])

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

