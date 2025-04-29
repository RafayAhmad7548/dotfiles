return {
	'stevearc/oil.nvim',
	---@module 'oil'
	---@type oil.SetupOpts
	opts = {
		use_default_keymaps = false,
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

          vim.cmd.wincmd('h')
          local bufname = vim.api.nvim_buf_get_name(0)
          local is_empty = bufname == '' and not vim.bo.modified

          if is_empty then
            vim.cmd(':q')
            oil.select({ vertical = true, split = 'topleft' }, function()
              vim.cmd.wincmd('l')
              vim.api.nvim_win_set_width(0, 40)
              vim.cmd.wincmd('h')
            end)
          else
            vim.cmd.wincmd('l')
            oil.select({ tab = true })
          end
        end
      end, nowait = true },

      -- shift space remapping
      ['<F26>'] = 'actions.parent',
		}
	},
	-- dependencies = { { 'echasnovski/mini.icons', opts = {} } },
	dependencies = { 'nvim-tree/nvim-web-devicons' }, -- use if you prefer nvim-web-devicons
	-- Lazy loading is not recommended because it is very tricky to make it work correctly in all situations.
	lazy = false,
}
