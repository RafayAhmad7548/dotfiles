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

  lua_ls = {
    settings = {
      Lua = {
	completion = {
	  callSnippet = 'Replace',
	},
      },
    },
  },
}

local ensure_installed = vim.tbl_keys(servers or {})

for server, config in pairs(servers) do
  vim.lsp.config(server, config)
end

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

  {

    'saghen/blink.cmp',
    event = 'VimEnter',
    version = '1.*',
    dependencies = {
      {
	'L3MON4D3/LuaSnip',
	version = '2.*',
	build = (function()
	  if vim.fn.has 'win32' == 1 or vim.fn.executable 'make' == 0 then
	    return
	  end
	  return 'make install_jsregexp'
	end)(),
	dependencies = {
	  -- `friendly-snippets` contains a variety of premade snippets.
	  --    See the README about individual language/framework/plugin snippets:
	  --    https://github.com/rafamadriz/friendly-snippets
	  -- {
	  --   'rafamadriz/friendly-snippets',
	  --   config = function()
	  --     require('luasnip.loaders.from_vscode').lazy_load()
	  --   end,
	  -- },
	},
	opts = {},
      },
      'folke/lazydev.nvim',
    },
    ---@module 'blink.cmp'
    ---@type blink.cmp.Config
    opts = {
      keymap = {
	preset = 'default',

	['<Tab>'] = { 'select_and_accept', 'snippet_forward', 'fallback'},
	['<S-Tab>'] = { 'snippet_backward', 'fallback'},
	['I'] = { 'scroll_documentation_up', 'fallback' },
	['K'] = { 'scroll_documentation_down', 'fallback' },

      },

      appearance = { nerd_font_variant = 'mono' },

      completion = {
	-- By default, you may press `<c-space>` to show the documentation.
	-- Optionally, set `auto_show = true` to show the documentation after a delay.
	documentation = { auto_show = false, auto_show_delay_ms = 500 },
      },

      sources = {
	default = { 'lsp', 'path', 'snippets', 'lazydev' },
	providers = {
	  lazydev = { module = 'lazydev.integrations.blink', score_offset = 100 },
	},
      },

      snippets = { preset = 'luasnip' },

      -- Blink.cmp includes an optional, recommended rust fuzzy matcher,
      -- which automatically downloads a prebuilt binary when enabled.
      --
      -- By default, we use the Lua implementation instead, but you may enable
      -- the rust implementation via `'prefer_rust_with_warning'`
      --
      -- See :h blink-cmp-config-fuzzy for more information
      fuzzy = { implementation = 'lua' },

      -- Shows a signature help window while you type arguments for a function
      signature = { enabled = true },
    },
  },

  {
    'neovim/nvim-lspconfig',
    dependencies = {
      -- Useful status updates for LSP.
      { 'j-hui/fidget.nvim', opts = {} },
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

    end
  },

  { 'mason-org/mason.nvim', opts = {} },

  {
    'mason-org/mason-lspconfig.nvim',
    opts = { ensure_installed = ensure_installed }
  },
}
