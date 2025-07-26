return {
  {
	-- `lazydev` configures Lua LSP for your Neovim config, runtime and plugins
	-- used for completion, annotations and signatures of Neovim apis
	'folke/lazydev.nvim',
	ft = 'lua',
	opts = {
	  library = {
		-- Load luvit types when the `vim.uv` word is found
		{ path = '${3rd}/luv/library', words = { 'vim%.uv' } },
	  },
	},
  },

  { 'williamboman/mason.nvim', opts = {} },

  {
	'neovim/nvim-lspconfig',
	dependencies = {
	  'williamboman/mason.nvim',
	  'williamboman/mason-lspconfig.nvim',

	  -- Useful status updates for LSP.
	  { 'j-hui/fidget.nvim', opts = {} },

	  'saghen/blink.cmp',
	},
	config = function()

	  vim.diagnostic.config {
		severity_sort = true,
		float = { border = 'rounded', source = 'if_many' },
		underline = { severity = vim.diagnostic.severity.ERROR },
		signs = vim.g.have_nerd_font and {
		  text = {
			[vim.diagnostic.severity.ERROR] = '󰅚 ',
			[vim.diagnostic.severity.WARN] = '󰀪 ',
			[vim.diagnostic.severity.INFO] = '󰋽 ',
		  },
		} or {},
		virtual_text = {
		  source = 'if_many',
		  spacing = 2,
		  format = function(diagnostic)
			local diagnostic_message = {
			  [vim.diagnostic.severity.ERROR] = diagnostic.message,
			  [vim.diagnostic.severity.WARN] = diagnostic.message,
			  [vim.diagnostic.severity.INFO] = diagnostic.message,
			  [vim.diagnostic.severity.HINT] = diagnostic.message,
			}
			return diagnostic_message[diagnostic.severity]
		  end,
		},
	  }

	  local capabilities = require('blink.cmp').get_lsp_capabilities()
	  local servers = {
		bashls = {},

		clangd = {},
		rust_analyzer = {},
		pyright = {},

		emmet_language_server = {},
		html = { filetypes = { 'html', 'htmldjango' }, },
		cssls = {},
		vtsls = {},

		prismals = {},

		-- kotlin_lsp = {},

		-- kotlin_language_server = {
		-- 	init_options = {
		-- 		storagePath = vim.fn.stdpath('cache') .. '/kotlin_language_server', -- Explicit storage path
		-- 	},
		-- },

		-- -- ... etc. See `:help lspconfig-all` for a list of all the pre-configured LSPs
		--
		-- Some languages (like typescript) have entire language plugins that can be useful:
		--    https://github.com/pmizio/typescript-tools.nvim
		--
		-- But for many setups, the LSP (`ts_ls`) will work just fine
		-- ts_ls = {},
		--

		lua_ls = {
		  -- cmd = { ... },
		  -- filetypes = { ... },
		  -- capabilities = {},
		  settings = {
			Lua = {
			  completion = {
				callSnippet = 'Replace',
			  },
			  -- You can toggle below to ignore Lua_LS's noisy `missing-fields` warnings
			  -- diagnostics = { disable = { 'missing-fields' } },
			},
		  },
		},
	  }

	  local ensure_installed = vim.tbl_keys(servers or {})

	  require('mason-lspconfig').setup {
		ensure_installed = ensure_installed,
		automatic_installation = false,
		handlers = {
		  function(server_name)
			local server = servers[server_name] or {}
			-- This handles overriding only values explicitly passed
			-- by the server configuration above. Useful when disabling
			-- certain features of an LSP (for example, turning off formatting for ts_ls)
			server.capabilities = vim.tbl_deep_extend('force', {}, capabilities, server.capabilities or {})
			require('lspconfig')[server_name].setup(server)
		  end,
		}
	  }
	  -- WARN: Temoraray workaround because of naming issue i.e. djlsp and django-template-server
	  require('lspconfig').djlsp.setup({})
	end
  },
}
