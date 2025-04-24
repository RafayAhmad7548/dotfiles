-- General --

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

-- Buffers --
vim.keymap.set('n', '<leader>l', ':tabnext<CR>', { desc = 'next buffer' })
vim.keymap.set('n', '<leader>j', ':tabprev<CR>', { desc = 'previous buffer' })

-- Telescope --
local builtin = require('telescope.builtin')

vim.keymap.set('n', '<C-o>', builtin.find_files, { desc = 'Telescope find files' })

vim.keymap.set('n', '<leader>/', function()
  -- You can pass additional configuration to Telescope to change the theme, layout, etc.
  builtin.current_buffer_fuzzy_find(require('telescope.themes').get_dropdown {
    winblend = 10,
    previewer = false,
  })
end, { desc = '[/] Fuzzily search in current buffer' })
