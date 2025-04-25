-- NOTE: General --

-- hjkl to ijkl remap
vim.keymap.set({ 'n', 'v', 'o' }, 'j', 'h', { desc = 'hjkl to ijkl' })
vim.keymap.set({ 'n', 'v', 'o' }, 'h', 'i', { desc = 'hjkl to ijkl' })
vim.keymap.set({ 'n', 'v', 'o' }, 'i', 'k', { desc = 'hjkl to ijkl' })
vim.keymap.set({ 'n', 'v', 'o' }, 'k', 'j', { desc = 'hjkl to ijkl' })

-- indentation
vim.keymap.set('n', '<Tab>', '>>', { desc = 'tab indent ' })
vim.keymap.set('n', '<S-Tab>', '<<', { desc = 'S-tab unindent ' })
vim.keymap.set({ 'v', 'o' }, '<Tab>', '>', { desc = 'tab indent ' })
vim.keymap.set({ 'v', 'o' }, '<S-Tab>', '<', { desc = 'S-tab unindent ' })

-- scrolling
vim.keymap.set({ 'n', 'v', 'o' }, '<C-d>', '<C-d>zz', { desc = 'centered scroll' })
vim.keymap.set({ 'n', 'v', 'o' }, '<C-u>', '<C-u>zz', { desc = 'centered scroll' })

-- start of line
vim.keymap.set({ 'n', 'v', 'o' }, '#', '_', { desc = '# start of line' })

-- save 
vim.keymap.set('n', '<C-s>', ':w<CR>', { desc = 'ctrl-s save' })

-- tabs 
vim.keymap.set('n', '<leader><Tab>', ':tabnext<CR>', { desc = 'next buffer' })
vim.keymap.set('n', '<leader><S-Tab>', ':tabprev<CR>', { desc = 'previous buffer' })

-- delete word in insert mode
vim.keymap.set('i', '<C-BS>', '<C-w>', { desc = 'delete word in insert mode' })

-- tab luasnip
-- TODO: fix this for snippets
vim.keymap.del('i', '<Tab>', { desc = 'remove keymap cause not be worky' })

-- NOTE: Terminal

vim.keymap.set('n', '<C-l>', function ()
  local buffers = vim.api.nvim_list_bufs()
  local terminal_exists = false
  for _, buf in ipairs(buffers) do
    local buf_name = vim.api.nvim_buf_get_name(buf)
    -- find all terminal buffers
    if vim.api.nvim_buf_is_loaded(buf) and string.find(buf_name, '^term://') ~= nil then

      -- find window of first terminal window if exists
      local window_exists = false
      local windows = vim.api.nvim_list_wins()
      for _, win in ipairs(windows) do
        if vim.api.nvim_win_get_buf(win) == buf then
          vim.api.nvim_set_current_win(win)
          window_exists = true
          break
        end
      end

      -- window dosnt exist so create and put existing terminal there
      if not window_exists then
        vim.cmd.vnew()
        vim.api.nvim_win_set_width(0, 60)
        vim.api.nvim_set_current_buf(buf)
      end

      terminal_exists = true
    end
  end

  -- if no terminal then create new one
  if not terminal_exists then
    vim.cmd.vnew()
    vim.cmd.term()
    vim.api.nvim_win_set_width(0, 60)
  end

  vim.api.nvim_feedkeys('a', 'n', true)

end, { desc = 'open terminal', silent = true })

vim.keymap.set('t', '<C-j>', '<cmd>wincmd h<CR>', { desc = 'focus editor', silent = true })
vim.keymap.set('t', '<C-w>', '<C-d>', { desc = 'kill terminal' })

vim.keymap.set('t', '<Esc>', '<C-\\><C-n>', { desc = 'normal mode in terminal' })

-- NOTE: Windows

-- this is weird because ctrl-i => Up & ctrl-k => Down in Kitty conf
vim.keymap.set({ 'n', 'v', 'o' }, '<Down><Up>', ':wincmd k<CR>', { desc = 'moving around window using ctrl-k ijkl', silent = true })
vim.keymap.set({ 'n', 'v', 'o' }, '<Down><Down>', ':wincmd j<CR>', { desc = 'moving around window using ctrl-k ijkl', silent = true })
vim.keymap.set({ 'n', 'v', 'o' }, '<Down><C-l>', ':wincmd l<CR>', { desc = 'moving around window using ctrl-k ijkl', silent = true })
vim.keymap.set({ 'n', 'v', 'o' }, '<Down><C-j>', ':wincmd h<CR>', { desc = 'moving around window using ctrl-k ijkl', silent = true })


-- NOTE: Telescope --

local builtin = require('telescope.builtin')

vim.keymap.set('n', '<C-o>', builtin.find_files, { desc = 'Telescope find files' })

vim.keymap.set('n', '<leader>/', function()
  -- You can pass additional configuration to Telescope to change the theme, layout, etc.
  builtin.current_buffer_fuzzy_find(require('telescope.themes').get_dropdown {
    winblend = 10,
    previewer = false,
  })
end, { desc = 'Fuzzily search in current buffer' })


local mappings = {
  telescope_defaults = function(actions)
    return {
      i = {
        ["<esc>"] = actions.close,
        ["<C-k>"] = actions.move_selection_next,
        ["<C-i>"] = actions.move_selection_previous,
      }
    }
  end

}
return mappings
