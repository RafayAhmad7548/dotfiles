return {
	-- {
	-- 	'akinsho/bufferline.nvim',
	-- 	version = "*",
	-- 	dependencies = 'nvim-tree/nvim-web-devicons',
	-- 	opts = {
	-- 		options = {
	-- 			custom_filter = function(buf, _)
	-- 				local buf_name = vim.api.nvim_buf_get_name(buf)
	-- 				if string.find(buf_name, '^term://') or string.find(buf_name, '^oil://') then
	-- 					return false
	-- 				end
	-- 				return true
	-- 			end,
	-- 			show_buffer_close_icons = false,
	-- 			-- style_preset = require('bufferline').style_preset.minimal
	-- 		}
	-- 	}
	-- },
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
