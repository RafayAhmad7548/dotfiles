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

require('lazy').setup({

  'tpope/vim-sleuth', -- Detect tabstop and shiftwidth automatically
  {
    'm4xshen/autoclose.nvim',
    config = function()
      require('autoclose').setup({})
    end
  },
  {
    'lewis6991/gitsigns.nvim',
    opts = {
      signs = {
          add          = { text = '┃' },
          change       = { text = '┃' },
          delete       = { text = '_' },
          topdelete    = { text = '‾' },
          changedelete = { text = '~' },
          untracked    = { text = '┆' },
        },
        signs_staged = {
          add          = { text = '┃' },
          change       = { text = '┃' },
          delete       = { text = '_' },
          topdelete    = { text = '‾' },
          changedelete = { text = '~' },
          untracked    = { text = '┆' },
        },
        signs_staged_enable = true,
        signcolumn = true
      }
  },

  {
      'nvim-telescope/telescope.nvim',
      dependencies = { 
        'nvim-lua/plenary.nvim',

        {
          'nvim-telescope/telescope-fzf-native.nvim',

          build = 'make',

          -- cond = function()
          --   return vim.fn.executable 'make' == 1
          -- end,
        },
      },
      config = function()
        local actions = require('telescope.actions')
        local actions_state = require('telescope.actions.state')
        require('telescope').setup({
          defaults = {
            mappings = {
              i = {
                ["<esc>"] = actions.close,
                ["<C-k>"] = actions.move_selection_next,
                ["<C-i>"] = actions.move_selection_previous,
              }

            }
          },
          pickers = {
            find_files = {
              mappings = {
                i = {
                  ["<CR>"] = function(prompt_bufnr)
                    local selection = actions_state.get_selected_entry()
                    actions.close(prompt_bufnr)
                    vim.cmd("tabnew " .. vim.fn.fnameescape(selection.path or selection.filename))
                  end
                }
              }
            }
          }         
        })
        pcall(require('telescope').load_extension, 'fzf')
      end
  },

  {
      'nanozuki/tabby.nvim',
      dependencies = 'nvim-tree/nvim-web-devicons',
      config = function()
        local theme = {
        -- this is carbonfox theme
          fill = 'TabLineFill',
          head = { fg = '#75beff', bg = '#1c1e26' },
          current_tab = { fg = '#1c1e26', bg = '#75beff' },
          tab = { fg = '#c5cdd9', bg = '#1c1e26' },
          win = { fg = '#1c1e26', bg = '#75beff' },
          tail = { fg = '#75beff', bg = '#1c1e26' },
        }

        require('tabby.tabline').set(function(line)
          return {
            {
              { '  ', hl = theme.head },
              line.sep('', theme.head, theme.fill),
            },
            line.tabs().foreach(function(tab)

              local hl = tab.is_current() and theme.current_tab or theme.tab

              -- remove count of wins in tab with [n+] included in tab.name()
              local name = tab.name()
              local index = string.find(name, "%[%d")
              local tab_name = index and string.sub(name, 1, index - 1) or name

              -- indicate if any of buffers in tab have unsaved changes
              local modified = false
              local win_ids = require('tabby.module.api').get_tab_wins(tab.id)
              for _, win_id in ipairs(win_ids) do
                  if pcall(vim.api.nvim_win_get_buf, win_id) then
                      local bufid = vim.api.nvim_win_get_buf(win_id)
                      if vim.api.nvim_buf_get_option(bufid, "modified") then
                          modified = true
                          break
                      end
                  end
              end

              return {
                line.sep('', hl, theme.fill),
                tab_name,
                modified and '',
                line.sep('', hl, theme.fill),
                hl = hl,
                margin = ' ',
              }
            end),
            line.spacer(),
            {
              line.sep('', theme.tail, theme.fill),
              { '  ', hl = theme.tail },
            },
            hl = theme.fill,
          }
        end)
      end
  },

  {
      'nvim-lualine/lualine.nvim',
      dependencies = { 'nvim-tree/nvim-web-devicons' },
      opts = {
        options = {
          theme = 'ayu_mirage'
        }
      }
  }
})


