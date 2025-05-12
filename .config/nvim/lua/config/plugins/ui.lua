return {
	{
		'nvim-lualine/lualine.nvim',
		dependencies = { 'nvim-tree/nvim-web-devicons' },
		opts = {}
	},

	{
		'navarasu/onedark.nvim',
		config = function ()
			require('onedark').setup({
				style = 'darker',
				code_style = {
					comments = 'none'
				}
			})
			require('onedark').load()
		end
	},
}
