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
  -- NOTE: General Editing --
  'tpope/vim-sleuth', -- Detect tabstop and shiftwidth automatically
  { 'folke/todo-comments.nvim', event = 'VimEnter', dependencies = { 'nvim-lua/plenary.nvim' }, opts = {} },

  -- TODO: i dunno about this one
  -- {
  --   "folke/noice.nvim",
  --   event = "VeryLazy",
  --   opts = {
  --   },
  --   dependencies = {
  --     -- if you lazy-load any plugin below, make sure to add proper `module="..."` entries
  --     "MunifTanjim/nui.nvim",
  --     -- OPTIONAL:
  --     --   `nvim-notify` is only needed, if you want to use the notification view.
  --     --   If not available, we use `mini` as the fallback
  --     "rcarriga/nvim-notify",
  --   }
  -- },

  -- { 'stevearc/dressing.nvim', opts = {}, },

  -- 'ThePrimeagen/vim-be-good',
  -- { 'vuciv/golf' },

  require('config.plugins.git'),
  require('config.plugins.ui'),
  require('config.plugins.telescope'),
  require('config.plugins.blinkcmp'),
  require('config.plugins.languages.lsp'),
  require('config.plugins.languages.treesitter'),
  require('config.plugins.harpoon'),
  require('config.plugins.autosession'),
  require('config.plugins.snacks'),
  require('config.plugins.mini'),

  require('config.plugins.languages.molten'),
  require('config.plugins.languages.flutter'),

})
