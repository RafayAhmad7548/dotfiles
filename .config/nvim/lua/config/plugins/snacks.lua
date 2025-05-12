return {
  'folke/snacks.nvim',
  priority = 1000,
  lazy = false,

  init = function()
    local Snacks = require('snacks')
    vim.api.nvim_create_autocmd("User", {
      pattern = "SnacksInputRename",
      callback = function ()
        Snacks.config.input.win.relative = "cursor"
        Snacks.config.input.win.col = -1
        Snacks.config.input.win.row = -3
        Snacks.config.input.win.title_pos = 'left'
      end
    })
    vim.api.nvim_create_autocmd("User", {
     pattern = "SnacksInputReset",
      callback = function ()
        Snacks.config.input.win.relative = "editor"
        Snacks.config.input.win.col = nil
        Snacks.config.input.win.row = 6
        Snacks.config.input.win.title_pos = 'center'
      end
    })
  end,


  ---@type snacks.Config
  opts = {
    -- your configuration comes here
    -- or leave it empty to use the default settings
    -- refer to the configuration section below
    bigfile = { enabled = true },
    dashboard = {
      enabled = true,
      preset = {
        header = [[
        ███╗   ██╗███████╗ ██████╗ ██╗   ██╗██╗███╗   ███╗
        ████╗  ██║██╔════╝██╔═══██╗██║   ██║██║████╗ ████║
        ██╔██╗ ██║█████╗  ██║   ██║██║   ██║██║██╔████╔██║
        ██║╚██╗██║██╔══╝  ██║   ██║╚██╗ ██╔╝██║██║╚██╔╝██║
        ██║ ╚████║███████╗╚██████╔╝ ╚████╔╝ ██║██║ ╚═╝ ██║
        ╚═╝  ╚═══╝╚══════╝ ╚═════╝   ╚═══╝  ╚═╝╚═╝     ╚═╝]],
      },
      sections = {
        { section = 'header' },
        { section = 'startup' },
      }
    },

    indent = {
      enabled = true,
      animate = { enabled = false },
    },
    input = {
      enabled = true,
      win = {},
    },
    quickfile = { enabled = true },
    rename = { enabled = true },

    bufdelete = { enabled = false },
    debug = { enabled = false },
    dim = { enabled = false },
    explorer = { enabled = false },
    git = { enabled = false },
    gitbrowse = { enabled = false },
    image = { enabled = false },
    layout = { enabled = false },
    lazygit = { enabled = false },
    notifier = { enabled = false },
    notify = { enabled = false },
    picker = { enabled = false },
    profiler = { enabled = false },
    scope = { enabled = false },
    scratch = { enabled = false },
    scroll = { enabled = false },
    statuscolumn = { enabled = false },
    terminal = { enabled = false },
    toggle = { enabled = false },
    win = { enabled = false },
    words = { enabled = false },
    zed = { enabled = false },
  },

}
