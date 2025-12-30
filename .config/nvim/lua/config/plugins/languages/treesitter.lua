return {
	'nvim-treesitter/nvim-treesitter',
	build = ':TSUpdate',
	main = 'nvim-treesitter.configs', -- Sets main module to use for opts
	opts = {
		ensure_installed = {
			'bash',
			'c',
			'cpp',
			'diff',
			'html',
			'css',
			'lua',
			'luadoc',
			'markdown',
			'markdown_inline',
			'query',
			'vim',
			'vimdoc',
			'rust',
			'python',
			'htmldjango',
			'r',
			'dart',
			'javascript',
			'typescript',
			'tsx',
			'prisma',
			'regex',
			'kotlin',
			'java',
		},
		auto_install = false,
		highlight = { enable = true, },
		indent = { enable = true },
	},
	-- There are additional nvim-treesitter modules that you can use to interact
	-- with nvim-treesitter. You should go explore a few and see what interests you:
	--
	--    - Incremental selection: Included, see `:help nvim-treesitter-incremental-selection-mod`
	--    - Show your current context: https://github.com/nvim-treesitter/nvim-treesitter-context
	--    - Treesitter + textobjects: https://github.com/nvim-treesitter/nvim-treesitter-textobjects
}
