return {
  'echasnovski/mini.nvim',
  version = '*' ,
  config = function()
    require('mini.pairs').setup({})
    require('mini.ai').setup({
      mappings = {
        around = 'a',
        inside = 'h',

        around_next = 'an',
        inside_next = 'hn',
        around_last = 'al',
        inside_last = 'hl',

        goto_left = 'g[',
        goto_right = 'g]',
      },
      silent = true,
    })
    require('mini.surround').setup({
      silent = true,
    })
    require('mini.files').setup({
      mappings = {
        go_in = 'l',
        go_out = 'j',
        go_in_plus = 'L',
        go_out_plus = 'J',
        synchronize = '<C-s>'
      }
    })
  end
}
