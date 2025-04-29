return {
  'nvim-telescope/telescope.nvim',
  dependencies = {
    'nvim-lua/plenary.nvim',

    {
      'nvim-telescope/telescope-fzf-native.nvim',
      build = 'make',
      cond = function()
        return vim.fn.executable 'make' == 1
      end,
    },
  },
  config = function()
    local actions = require('telescope.actions')
    local actions_state = require('telescope.actions.state')
    require('telescope').setup({
      defaults = {
        mappings = {
          i = {
            ['<esc>'] = actions.close,
          }
        }
      },
      pickers = {
        find_files = {
          mappings = {
            i = {
              ['<CR>'] = function(prompt_bufnr)
                local selection = actions_state.get_selected_entry()
                actions.close(prompt_bufnr)

                local bufname = vim.api.nvim_buf_get_name(0)
                local is_empty = bufname == '' and not vim.bo.modified

                if is_empty then
                  vim.cmd('edit' .. vim.fn.fnameescape(selection.path or selection.filename))
                else
                  vim.cmd('tabnew ' .. vim.fn.fnameescape(selection.path or selection.filename))
                end
              end
            }
          }
        }
      }
    })
    pcall(require('telescope').load_extension, 'fzf')

    -- NOTE: Mappings --

    local builtin = require('telescope.builtin')

    vim.keymap.set('n', '<C-o>', builtin.find_files, { desc = 'Telescope find files' })

    vim.keymap.set('n', '<leader>/', function()
      -- You can pass additional configuration to Telescope to change the theme, layout, etc.
      builtin.current_buffer_fuzzy_find(require('telescope.themes').get_dropdown {
        winblend = 10,
        previewer = false,
      })
    end, { desc = 'Fuzzily search in current buffer' })

  end
}
