vim.api.nvim_create_autocmd('FileType', {
  callback = function ()
    pcall(vim.treesitter.start)
  end
})

return {
  'nvim-treesitter/nvim-treesitter',
  build = ':TSUpdate',
  config = function()
    require('nvim-treesitter').install({
      'bash',
      'fish',
      'c',
      'cpp',
      'diff',
      'html',
      'css',
      'javascript',
      'typescript',
      'tsx',
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
      'prisma',
      'sql',
      'regex',
      'kotlin',
      'java',
      'http',
    })
  end,
}
