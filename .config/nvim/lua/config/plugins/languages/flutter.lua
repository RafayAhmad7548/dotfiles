return {
    'nvim-flutter/flutter-tools.nvim',
    lazy = false,
    dependencies = { 'nvim-lua/plenary.nvim', },
    config = function()
        require('flutter-tools').setup({})
        vim.keymap.set('n', '<leader>fd', '<cmd>FlutterDevices<CR>', { desc = 'show flutter devices' })
        vim.keymap.set('n', '<leader>fq', '<cmd>FlutterQuit<CR>', { desc = 'stop flutter' })
    end,
}
