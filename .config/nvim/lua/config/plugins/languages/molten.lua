return {
	{
		'3rd/image.nvim',
		version = '1.1.0',
		build = false, -- so that it doesn't build the rock https://github.com/3rd/image.nvim/issues/91#issuecomment-2453430239
		opts = {
			backend = 'kitty', -- whatever backend you would like to use
			max_width = 100,
			max_height = 20,
			max_height_window_percentage = math.huge,
			max_width_window_percentage = math.huge,
			window_overlap_clear_enabled = true, -- toggles images when windows are overlapped
			window_overlap_clear_ft_ignore = { 'cmp_menu', 'cmp_docs', '' },
		}

	},
	{
		'benlubas/molten-nvim',
		version = '^1.0.0', -- use version <2.0.0 to avoid breaking changes
		dependencies = { '3rd/image.nvim' },
		build = ':UpdateRemotePlugins',
		init = function()
			-- these are examples, not defaults. Please see the readme
			vim.g.molten_image_provider = 'image.nvim'
		end,
	}
}
