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
    require('telescope').setup({
      defaults = {
        mappings = {
          i = {
            ['<esc>'] = actions.close,
          }
        }
      },
      pickers = {
        mappings = {
          i = {
            ['<C-s>'] = actions.file_split,
            ['<C-v>'] = actions.file_vsplit
          }
        }
      }
    })
    pcall(require('telescope').load_extension, 'fzf')

    -- NOTE: Mappings --

    local builtin = require('telescope.builtin')

    vim.keymap.set('n', '<leader>sf', builtin.find_files, { desc = 'Telescope find files' })

    vim.keymap.set('n', '<leader>sp', '<cmd>SessionSearch<CR>', { desc = 'Search Sessions' })

    vim.keymap.set('n', '<leader>/', function()
      -- You can pass additional configuration to Telescope to change the theme, layout, etc.
      builtin.current_buffer_fuzzy_find(require('telescope.themes').get_dropdown {
        winblend = 10,
        previewer = false,
      })
    end, { desc = 'Fuzzily search in current buffer' })

  end
}
