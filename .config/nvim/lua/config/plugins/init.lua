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
  {
    'm4xshen/autoclose.nvim',
    opts = {
      keys = {
        ['%'] = { close = true, escape = true, pair = '%%', enabled_filetypes = { 'htmldjango' } },
      },
      options = { disable_when_touch = true, }
    }
  },
  { 'folke/todo-comments.nvim', event = 'VimEnter', dependencies = { 'nvim-lua/plenary.nvim' }, opts = {} },

  {
    'lukas-reineke/indent-blankline.nvim',
    main = 'ibl',
    ---@module 'ibl'
    ---@type ibl.config
    opts = {},
  },

  'ThePrimeagen/vim-be-good',

  require('config.plugins.oil'),
  require('config.plugins.git'),
  require('config.plugins.ui'),
  require('config.plugins.telescope'),
  require('config.plugins.blinkcmp'),
  require('config.plugins.lsp'),
  require('config.plugins.treesitter'),
  require('config.plugins.harpoon'),
  require('config.plugins.autosession'),

  require('config.plugins.molten'),


  -- NOTE: maybe revisit this later
  -- {
  --   'brenton-leighton/multiple-cursors.nvim',
  --   version = '*',  -- Use the latest tagged version
  --   opts = {
  --     custom_key_maps = keymaps.multicursor_custom()
  --   },  -- This causes the plugin setup function to be called
  --   keys = keymaps.multicursor(),
  -- },


})
