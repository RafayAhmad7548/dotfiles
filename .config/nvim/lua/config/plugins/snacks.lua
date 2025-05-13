return {
  'folke/snacks.nvim',
  priority = 1000,
  lazy = false,

  init = function()
    local Snacks = require('snacks')
    vim.api.nvim_create_autocmd('User', {
      pattern = 'SnacksInputRename',
      callback = function ()
        Snacks.config.input.win.relative = 'cursor'
        Snacks.config.input.win.col = -1
        Snacks.config.input.win.row = -3
        Snacks.config.input.win.title_pos = 'left'
      end
    })
    vim.api.nvim_create_autocmd('User', {
     pattern = 'SnacksInputReset',
      callback = function ()
        Snacks.config.input.win.relative = 'editor'
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

    picker = {
      enabled = true,
      matcher = { frecency = true, },
      layout = {
        cycle = true,
        preset = 'telescope',
      },
      ui_select = true,
      win = {
        input = {
          keys = {
            ['<Esc>'] = { 'close', mode = 'i' },
            ['<C-s>'] = { 'edit_split', mode =  'i' },
            ['<C-v>'] = { 'edit_vsplit', mode = 'i' },
            ['<c-d>'] = { 'preview_scroll_down', mode = 'i' },
            ['<c-u>'] = { 'preview_scroll_up', mode = 'i' },
          }
        }
      },

      layouts = {
        telescope = {
          reverse = true,
          layout = {
            box = 'horizontal',
            backdrop = false,
            width = 0.8,
            height = 0.9,
            border = 'none',
            {
              box = 'vertical',
              { win = 'list', title = ' Results ', title_pos = 'center', border = 'rounded' },
              { win = 'input', height = 1, border = 'rounded', title = '{title} {live} {flags}', title_pos = 'center' },
            },
            {
              win = 'preview',
              title = '{preview:Preview}',
              width = 0.55,
              border = 'rounded',
              title_pos = 'center',
            },
          }
        }
      }
    },

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
