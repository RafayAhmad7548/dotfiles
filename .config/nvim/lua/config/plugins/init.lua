-- [[ Install `lazy.nvim` plugin manager ]]
--    See `:help lazy.nvim.txt` or https://github.com/folke/lazy.nvim for more info
local lazypath = vim.fn.stdpath 'data' .. '/lazy/lazy.nvim'
if not (vim.uv or vim.loop).fs_stat(lazypath) then
  local lazyrepo = 'https://github.com/folke/lazy.nvim.git'
  local out = vim.fn.system { 'git', 'clone', '--filter=blob:none', '--branch=stable', lazyrepo, lazypath }
  if vim.v.shell_error ~= 0 then
    error('Error cloning lazy.nvim:\n' .. out)
  end
end ---@diagnostic disable-next-line: undefined-field
vim.opt.rtp:prepend(lazypath)

-- local keymaps = require('config.pluginmaps')

require('lazy').setup({
  -- INFO: General Editing --
  'tpope/vim-sleuth', -- Detect tabstop and shiftwidth automatically
  { 'folke/todo-comments.nvim', event = 'VimEnter', dependencies = { 'nvim-lua/plenary.nvim' }, opts = {} },

  -- { 'stevearc/dressing.nvim', opts = {}, },

  -- 'ThePrimeagen/vim-be-good',
  -- { 'vuciv/golf' },

  require('config.plugins.git'),
  require('config.plugins.ui'),
  -- require('config.plugins.telescope'),
  require('config.plugins.languages.lsp'),
  require('config.plugins.languages.treesitter'),
  require('config.plugins.harpoon'),
  require('config.plugins.autosession'),
  require('config.plugins.snacks'),
  require('config.plugins.mini'),

  require('config.plugins.languages.notebook'),
  require('config.plugins.languages.flutter'),
  require('config.plugins.languages.markdown'),

})
