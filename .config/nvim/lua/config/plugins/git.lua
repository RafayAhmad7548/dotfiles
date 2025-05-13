return {
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
			signcolumn = true,

			on_attach = function()
				local gitsigns = require('gitsigns')

				vim.keymap.set('n', '<leader>gs', gitsigns.stage_hunk, { desc = 'stage hunk' })
				vim.keymap.set('n', '<leader>gr', gitsigns.reset_hunk, { desc = 'restore hunk' })

				vim.keymap.set('n', '<leader>gS', gitsigns.stage_buffer, { desc = 'stage buffer' })
				vim.keymap.set('n', '<leader>gR', gitsigns.stage_hunk, { desc = 'reset buffer' })

				vim.keymap.set('n', '<leader>gp', gitsigns.preview_hunk, { desc = 'preview hunk' })
				vim.keymap.set('n', '<leader>gb', gitsigns.blame_line, { desc = 'blame line' })


			end
		},
	},
	{
		'sindrets/diffview.nvim',
		config = function ()
			local actions = require('diffview.config').actions
			require('diffview').setup({
				keymaps = {
					disable_defaults = true,
					file_panel = {
						['i'] = '<Up>',
						['k'] = '<Down>',
						['j'] = false,

						['<Space>'] = function () actions.toggle_stage_entry() end

					}
				}
			})
		end
	},
	-- {
	-- 	'NeogitOrg/neogit',
	-- 	dependencies = {
	-- 		'nvim-lua/plenary.nvim',
	-- 		'nvim-telescope/telescope.nvim',
	-- 	},
	-- 	config = function()
	-- 		require('neogit').setup({
	--
	-- 			kind = 'floating',
	-- 			graph_style = 'kitty',
	-- 			disable_line_numbers = false,
	-- 			disable_relative_line_numbers = false,
	-- 			commit_editor = {
	-- 				kind = 'floating',
	-- 			},
	-- 			commit_select_view = {
	-- 				kind = 'floating',
	-- 			},
	-- 			commit_view = {
	-- 				kind = 'floating',
	-- 				verify_commit = vim.fn.executable('gpg') == 1, -- Can be set to true or false, otherwise we try to find the binary
	-- 			},
	-- 			log_view = {
	-- 				kind = 'floating',
	-- 			},
	-- 			rebase_editor = {
	-- 				kind = 'floating',
	-- 			},
	-- 			reflog_view = {
	-- 				kind = 'floating',
	-- 			},
	-- 			merge_editor = {
	-- 				kind = 'floating',
	-- 			},
	-- 			description_editor = {
	-- 				kind = 'floating',
	-- 			},
	-- 			tag_editor = {
	-- 				kind = 'floating',
	-- 			},
	-- 			preview_buffer = {
	-- 				kind = 'floating',
	-- 			},
	-- 			popup = {
	-- 				kind = 'floating',
	-- 			},
	-- 			stash = {
	-- 				kind = 'floating',
	-- 			},
	-- 			refs_view = {
	-- 				kind = 'floating',
	-- 			},
	-- 			mappings = {
	-- 				status = {
	-- 					['i'] = 'MoveUp',
	-- 					['k'] = 'MoveDown',
	-- 					['j'] = false,
	-- 				},
	-- 			}
	-- 		})
	-- 		vim.keymap.set('n', '<leader>gg', '<cmd>Neogit<CR>', { desc = 'open neogit '})
	-- 	end
	-- }
	-- {
	-- 	'tpope/vim-fugitive',
	-- }
	-- {
	-- 	'sindrets/diffview.nvim',
	-- 	dependencies = { 'nvim-tree/nvim-web-devicons' },
	-- 	-- lazy, only load diffview by these commands
	-- 	cmd = {
	-- 		'DiffviewFileHistory', 'DiffviewOpen', 'DiffviewToggleFiles', 'DiffviewFocusFiles', 'DiffviewRefresh'
	-- 	}
	-- },
	-- {
	--   'SuperBo/fugit2.nvim',
	--   build = false,
	--   opts = {
	-- 	width = 100,
	--   },
	--   dependencies = {
	-- 	'MunifTanjim/nui.nvim',
	-- 	'nvim-tree/nvim-web-devicons',
	-- 	'nvim-lua/plenary.nvim',
	-- 	-- {
	-- 	--   'chrisgrieser/nvim-tinygit', -- optional: for Github PR view
	-- 	--   dependencies = { 'stevearc/dressing.nvim' }
	-- 	-- },
	--   },
	--   cmd = { 'Fugit2', 'Fugit2Diff', 'Fugit2Graph' },
	--   keys = {
	-- 	{ '<leader>F', mode = 'n', '<cmd>Fugit2<cr>' }
	--   }
	-- },
}
