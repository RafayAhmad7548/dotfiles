return {
  'stevearc/oil.nvim',
  ---@module 'oil'
  ---@type oil.SetupOpts
  opts = {
    use_default_keymaps = false,
    buf_options = {
      buflisted = true
    },
    keymaps = {
      ['<C-j>'] = { '<Down><C-j>', remap = true },

      ['<Space>'] = { callback = function()
        local oil = require('oil')

        local cursor_entry = oil.get_cursor_entry()

        if not cursor_entry then
          return
        end
        if cursor_entry.type == 'directory' then
          oil.select()
        else
          oil.select(nil, function()
            vim.cmd.wincmd('h')
            local buf_name = vim.api.nvim_buf_get_name(0)
            local is_empty = buf_name == '' and not vim.bo.modified
            if is_empty then
              -- delete empty buffer
              vim.cmd('bd')
            else
              -- close window of not empty buffer
              vim.cmd('q')
            end
          end)
        end
      end, nowait = true },

      -- shift space remapping
      ['<F26>'] = 'actions.parent',

      ['<C-w>'] = { callback = function()
        vim.cmd('bd')
      end, nowait = true }
    }
  },
  -- dependencies = { { 'echasnovski/mini.icons', opts = {} } },
  dependencies = { 'nvim-tree/nvim-web-devicons' }, -- use if you prefer nvim-web-devicons
  -- Lazy loading is not recommended because it is very tricky to make it work correctly in all situations.
  lazy = false,
}
