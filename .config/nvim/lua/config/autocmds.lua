vim.api.nvim_create_autocmd('TextYankPost', {
  desc = 'Highlight when yanking (copying) text',
  group = vim.api.nvim_create_augroup('kickstart-highlight-yank', { clear = true }),
  callback = function()
    vim.highlight.on_yank()
  end,
})

vim.api.nvim_create_autocmd('User', {
  pattern = 'MiniFilesActionRename',
  callback = function(event)
    require('snacks').rename.on_rename_file(event.data.from, event.data.to)
  end,
})

vim.api.nvim_create_autocmd("FileType", {
  pattern = "man",
  callback = function()
    vim.keymap.del("n", "k", { buffer = true })
    vim.keymap.del("n", "j", { buffer = true })
  end,
})

-- use this maybe or maybe not
-- vim.api.nvim_create_autocmd('TermOpen', {
--   pattern = '*',
--   callback = function ()
--     vim.fn.chansend(vim.b.terminal_job_id, 'alias vi="nvr -cc tabnew"\n\x0c')
--   end
-- })
