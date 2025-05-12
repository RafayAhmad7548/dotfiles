-- NOTE: General --

-- hjkl to ijkl remap
vim.keymap.set({ 'n', 'v', 'o' }, 'j', 'h', { desc = 'hjkl to ijkl' })
vim.keymap.set({ 'n', 'v', 'o' }, 'h', 'i', { desc = 'hjkl to ijkl' })
vim.keymap.set({ 'n', 'v', 'o' }, 'i', 'k', { desc = 'hjkl to ijkl' })
vim.keymap.set({ 'n', 'v', 'o' }, 'k', 'j', { desc = 'hjkl to ijkl' })

-- indentation
vim.keymap.set('n', '<Tab>', '>>', { desc = 'tab indent ' })
vim.keymap.set('n', '<S-Tab>', '<<', { desc = 'S-tab unindent ' })
vim.keymap.set({ 'v', 'o' }, '<Tab>', '>', { desc = 'tab indent ' })
vim.keymap.set({ 'v', 'o' }, '<S-Tab>', '<', { desc = 'S-tab unindent ' })

-- scrolling
vim.keymap.set({ 'n', 'v' }, '<C-d>', '<C-d>zz', { desc = 'centered scroll' })
vim.keymap.set({ 'n', 'v' }, '<C-u>', '<C-u>zz', { desc = 'centered scroll' })
vim.keymap.set({ 'n', 'v' }, '<C-o>', '<C-o>zz', { desc = 'centered jump back' })

-- start of line
vim.keymap.set({ 'n', 'v', 'o' }, '#', '_', { desc = '# start of line' })

-- save / quit
vim.keymap.set('n', '<C-s>', ':w<CR>', { desc = 'ctrl-s save' })
vim.keymap.set('n', '<C-w>', ':bd<CR>', { desc = 'save and close', nowait = true })

-- delete word in insert mode
vim.keymap.set('i', '<C-BS>', '<C-w>', { desc = 'delete word in insert mode' })



-- NOTE: Right Dock: Terminal & MiniOilFiles

-- NOTE: ctrl m
vim.keymap.set('n', '<F27>', '<cmd>Floaterminal<CR>', { desc = 'open terminal', nowait = true })
vim.keymap.set('t', '<F27>', '<cmd>q<CR>', { desc = 'close terminal window' })

vim.keymap.set('t', '<C-l>', '<cmd>Floaterminal 1<CR>', { desc = 'terminal 1' })
vim.keymap.set('t', '<C-j>', '<cmd>Floaterminal 2<CR>', { desc = 'terminal 2' })
vim.keymap.set('t', '<Down>', '<cmd>Floaterminal 3<CR>', { desc = 'terminal 3' })
vim.keymap.set('t', '<Up>', '<cmd>Floaterminal 4<CR>', { desc = 'terminal 4' })

vim.keymap.set('t', '<C-w>', '<C-d>', { desc = 'kill terminal' })

vim.keymap.set('t', '<Esc>', '<C-\\><C-n>', { desc = 'normal mode in terminal' })

vim.keymap.set('n', '<C-e>', require('mini.files').open, { desc = 'open mini files' })


-- NOTE: Windows

-- this is weird because ctrl-i => Up & ctrl-k => Down in Kitty conf
vim.keymap.set({ 'n', 'v', 'o' }, '<leader>ki', ':wincmd k<CR>', { desc = 'move focus between windows', silent = true })
vim.keymap.set({ 'n', 'v', 'o' }, '<leader>kk', ':wincmd j<CR>', { desc = 'move focus between windows', silent = true })
vim.keymap.set({ 'n', 'v', 'o' }, '<leader>kl', ':wincmd l<CR>', { desc = 'move focus between windows', silent = true })
vim.keymap.set({ 'n', 'v', 'o' }, '<leader>kj', ':wincmd h<CR>', { desc = 'move focus between windows', silent = true })


-- NOTE: LSP

--  This function gets run when an LSP attaches to a particular buffer.
--    That is to say, every time a new file is opened that is associated with
--    an lsp (for example, opening `main.rs` is associated with `rust_analyzer`) this
--    function will be executed to configure the current buffer
vim.api.nvim_create_autocmd('LspAttach', {
  group = vim.api.nvim_create_augroup('kickstart-lsp-attach', { clear = true }),
  callback = function(event)

    local builtin = require('telescope.builtin')

    local map = function(keys, func, desc, mode)
      mode = mode or 'n'
      vim.keymap.set(mode, keys, func, { buffer = event.buf, desc = 'LSP: ' .. desc, nowait = true })
    end

    -- Rename the variable under your cursor.
    --  Most Language Servers support renaming across files, etc.
    map('<F2>', function()
      vim.api.nvim_exec_autocmds("User", { pattern = "SnacksInputRename" })
      vim.lsp.buf.rename()
      vim.api.nvim_create_autocmd("WinClosed", {
        callback = function (args)
          vim.api.nvim_exec_autocmds("User", {
            pattern = "SnacksInputReset"
          })
          vim.api.nvim_del_autocmd(args.id)
        end
      })
    end, '[R]e[n]ame')

    -- Execute a code action, usually your cursor needs to be on top of an error
    -- or a suggestion from your LSP for this to activate.
    map('ga', vim.lsp.buf.code_action, '[G]oto Code [A]ction', { 'n', 'x' })

    -- Find references for the word under your cursor.
    map('gr', builtin.lsp_references, '[G]oto [R]eferences')

    -- Jump to the implementation of the word under your cursor.
    --  Useful when your language has ways of declaring types without an actual implementation.
    map('gi', builtin.lsp_implementations, '[G]oto [I]mplementation')

    -- Jump to the definition of the word under your cursor.
    --  This is where a variable was first declared, or where a function is defined, etc.
    --  To jump back, press <C-t>.
    map('gd', builtin.lsp_definitions, '[G]oto [D]efinition')

    -- WARN: This is not Goto Definition, this is Goto Declaration.
    --  For example, in C this would take you to the header.
    map('gD', vim.lsp.buf.declaration, '[G]oto [D]eclaration')

    -- Fuzzy find all the symbols in your current document.
    --  Symbols are things like variables, functions, types, etc.
    map('go', builtin.lsp_document_symbols, 'Open Document Symbols')

    -- Fuzzy find all the symbols in your current workspace.
    --  Similar to document symbols, except searches over your entire project.
    map('gO', builtin.lsp_dynamic_workspace_symbols, 'Open Workspace Symbols')

    -- Jump to the type of the word under your cursor.
    --  Useful when you're not sure what type a variable is and you want to see
    --  the definition of its *type*, not where it was *defined*.
    map('gt', builtin.lsp_type_definitions, '[G]oto [T]ype Definition')

    -- This function resolves a difference between neovim nightly (version 0.11) and stable (version 0.10)
    ---@param client vim.lsp.Client
    ---@param method vim.lsp.protocol.Method
    ---@param bufnr? integer some lsp support methods only in specific files
    ---@return boolean
    local function client_supports_method(client, method, bufnr)
      if vim.fn.has 'nvim-0.11' == 1 then
        return client:supports_method(method, bufnr)
      else
        return client.supports_method(method, { bufnr = bufnr })
      end
    end

    -- The following two autocommands are used to highlight references of the
    -- word under your cursor when your cursor rests there for a little while.
    --    See `:help CursorHold` for information about when this is executed
    --
    -- When you move your cursor, the highlights will be cleared (the second autocommand).
    local client = vim.lsp.get_client_by_id(event.data.client_id)
    if client and client_supports_method(client, vim.lsp.protocol.Methods.textDocument_documentHighlight, event.buf) then
      local highlight_augroup = vim.api.nvim_create_augroup('kickstart-lsp-highlight', { clear = false })
      vim.api.nvim_create_autocmd({ 'CursorHold', 'CursorHoldI' }, {
        buffer = event.buf,
        group = highlight_augroup,
        callback = vim.lsp.buf.document_highlight,
      })

      vim.api.nvim_create_autocmd({ 'CursorMoved', 'CursorMovedI' }, {
        buffer = event.buf,
        group = highlight_augroup,
        callback = vim.lsp.buf.clear_references,
      })

      vim.api.nvim_create_autocmd('LspDetach', {
        group = vim.api.nvim_create_augroup('kickstart-lsp-detach', { clear = true }),
        callback = function(event2)
          vim.lsp.buf.clear_references()
          vim.api.nvim_clear_autocmds { group = 'kickstart-lsp-highlight', buffer = event2.buf }
        end,
      })
    end

    -- The following code creates a keymap to toggle inlay hints in your
    -- code, if the language server you are using supports them
    --
    -- This may be unwanted, since they displace some of your code
    if client and client_supports_method(client, vim.lsp.protocol.Methods.textDocument_inlayHint, event.buf) then
      map('<leader>ih', function()
        vim.lsp.inlay_hint.enable(not vim.lsp.inlay_hint.is_enabled { bufnr = event.buf })
      end, '[T]oggle Inlay [H]ints')
    end
  end,
})

-- NOTE: Molten
vim.keymap.set("n", "<leader>mi", ":MoltenInit<CR>",
    { silent = true, desc = "Initialize the plugin" })
vim.keymap.set("n", "<leader>mo", ":MoltenEvaluateOperator<CR>",
    { silent = true, desc = "run operator selection" })
vim.keymap.set("n", "<leader>ml", ":MoltenEvaluateLine<CR>",
    { silent = true, desc = "evaluate line" })
vim.keymap.set("v", "<leader>mv", ":<C-u>MoltenEvaluateVisual<CR>gv",
    { silent = false, desc = "evaluate visual selection" })
vim.keymap.set("n", "<leader>mc", ":MoltenReevaluateCell<CR>",
    { silent = false, desc = "reevaluate cell" })
vim.keymap.set("n", "<leader>me", ":noautocmd MoltenEnterOutput<CR>",
    { silent = true, desc = "show/enter output" })
vim.keymap.set("n", "<leader>mh", ":MoltenHideOutput<CR>",
    { silent = true, desc = "hide output" })
