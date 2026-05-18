return {
  {
    'lewis6991/gitsigns.nvim',
    -- dir = '~/Stuff/Coding/gitsigns.nvim',
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
	vim.keymap.set('n', '<leader>gB', gitsigns.blame, { desc = 'blame' })

      end
    },
  },
  {
    'sindrets/diffview.nvim',
    config = function ()
      local actions = require('diffview.config').actions
      require('diffview').setup({
	view = {
	  merge_tool = {
	    layout = 'diff3_mixed',
	  },
	},
	keymaps = {
	  disable_defaults = true,
	  view = {
	    { "n", "<c-n>",          actions.select_next_entry,              { desc = "Open the diff for the next file" } },
	    { "n", "<c-p>",	     actions.select_prev_entry,              { desc = "Open the diff for the previous file" } },
	    { "n", "[x",             actions.prev_conflict,                  { desc = "Go to the previous conflict" } },
	    { "n", "]x",             actions.next_conflict,                  { desc = "Go to the next conflict" } },
	  },
	  file_panel = {
	    { "n", "k",              actions.next_entry,                     { desc = "Bring the cursor to the next file entry" } },
	    { "n", "i",              actions.prev_entry,                     { desc = "Bring the cursor to the previous file entry" } },
	    { "n", "<CR>",           actions.select_entry,                   { desc = "Open the diff for the selected entry" } },
	    { "n", "l",              actions.select_entry,                   { desc = "Open the diff for the selected entry" } },
	    { "n", "s",              actions.toggle_stage_entry,             { desc = "Stage / unstage the selected entry" } },
	    { "n", "S",              actions.stage_all,                      { desc = "Stage all entries" } },
	    { "n", "U",              actions.unstage_all,                    { desc = "Unstage all entries" } },
	    { "n", "<c-n>",          actions.select_next_entry,              { desc = "Open the diff for the next file" } },
	    { "n", "<c-p>",	     actions.select_prev_entry,              { desc = "Open the diff for the previous file" } },
	    { "n", "[x",             actions.prev_conflict,                  { desc = "Go to the previous conflict" } },
	    { "n", "]x",             actions.next_conflict,                  { desc = "Go to the next conflict" } },
	    { "n", "g?",             actions.help("file_panel"),             { desc = "Open the help panel" } },

	    -- { "n", "<leader>cO",     actions.conflict_choose_all("ours"),    { desc = "Choose the OURS version of a conflict for the whole file" } },
	    -- { "n", "<leader>cT",     actions.conflict_choose_all("theirs"),  { desc = "Choose the THEIRS version of a conflict for the whole file" } },
	    -- { "n", "<leader>cB",     actions.conflict_choose_all("base"),    { desc = "Choose the BASE version of a conflict for the whole file" } },
	    -- { "n", "<leader>cA",     actions.conflict_choose_all("all"),     { desc = "Choose all the versions of a conflict for the whole file" } },
	    -- { "n", "dX",             actions.conflict_choose_all("none"),    { desc = "Delete the conflict region for the whole file" } },

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
