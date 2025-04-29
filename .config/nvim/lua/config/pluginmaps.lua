-- NOTE: Revisit Later
return {
  multicursor = function()
    return {
      {'i', 'k', mode = {'n'}},
      {'<F27>', '<Cmd>MultipleCursorsAddUp<CR>', mode = {'n', 'x'}, desc = 'Add cursor and move up'},
      {'<F28>', '<Cmd>MultipleCursorsAddDown<CR>', mode = {'n', 'x'}, desc = 'Add cursor and move down'},

      {'<C-LeftMouse>', '<Cmd>MultipleCursorsMouseAddDelete<CR>', mode = {'n', 'i'}, desc = 'Add or remove cursor'},

      -- {'<Leader>m', '<Cmd>MultipleCursorsAddVisualArea<CR>', mode = {'x'}, desc = 'Add cursors to the lines of the visual area'},

      {'<Leader>a', '<Cmd>MultipleCursorsAddMatches<CR>', mode = {'n', 'x'}, desc = 'Add cursors to cword'},
      {'<Leader>A', '<Cmd>MultipleCursorsAddMatchesV<CR>', mode = {'n', 'x'}, desc = 'Add cursors to cword in previous area'},

      {'<C-n>', '<Cmd>MultipleCursorsAddJumpNextMatch<CR>', mode = {'n', 'x'}, desc = 'Add cursor and jump to next cword'},
      -- {'q', '<Cmd>MultipleCursorsJumpNextMatch<CR>', mode = {'n', 'x'}, desc = 'Jump to next cword'},
      -- {'Q', '<Cmd>MultipleCursorsJumpPrevMatch<CR>', mode = {'n', 'x'}, desc = 'Jump to next cword'},

      -- {'<Leader>l', '<Cmd>MultipleCursorsLock<CR>', mode = {'n', 'x'}, desc = 'Lock virtual cursors'},
    }
  end,

  multicursor_custom = function()
    return {
      {{'n', 'x' }, 'i', function()
        local pos = vim.api.nvim_win_get_cursor(0)
        vim.api.nvim_win_set_cursor(0, {math.max(pos[1] - 1, 1), pos[2]})
      end},
      {{'n', 'x' }, 'j', function()
        local pos = vim.api.nvim_win_get_cursor(0)
        vim.api.nvim_win_set_cursor(0, {pos[1], math.max(pos[2] - 1, 0)})
      end},
      {{'n', 'x' }, 'k', function()
        local pos = vim.api.nvim_win_get_cursor(0)
        local lines = vim.api.nvim_buf_line_count(0)
        vim.api.nvim_win_set_cursor(0, {math.min(pos[1] + 1, lines), pos[2]})
      end},
      {{'n', 'x' }, 'h', function()
        vim.cmd('startinsert')
      end},
    }
  end

}
