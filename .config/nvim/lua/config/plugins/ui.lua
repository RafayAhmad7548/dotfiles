return {
	{
		'nvim-lualine/lualine.nvim',
		dependencies = { 'nvim-tree/nvim-web-devicons' },
		opts = {}
	},

	{
		'catppuccin/nvim',
		name = 'catppuccin',
		priority = 1000,
		opts = {
			flavour = 'mocha',
			no_italic = true,
		},
		config = function()
			vim.cmd('colorscheme catppuccin')
		end
	}
}
