return {
    'nvim-flutter/flutter-tools.nvim',
    lazy = false,
    dependencies = { 'nvim-lua/plenary.nvim', },
    config = function()
        require('flutter-tools').setup({
            fvm = true,
            dev_log = {
                open_cmd = 'FloutterLog',
            }
        })
    end,
}
