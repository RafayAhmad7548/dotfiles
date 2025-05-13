return {
  'rmagatti/auto-session',
  lazy = false,

  ---enables autocomplete for opts
  ---@module 'auto-session'
  ---@type AutoSession.Config
  opts = {
    suppressed_dirs = { '~/', '~/Downloads', '/' },
    pre_save_cmds = {
      function()
        local bufs = vim.api.nvim_list_bufs()
        for _, buf in ipairs(bufs) do
          if vim.bo[buf].buftype == 'terminal' then
            vim.api.nvim_buf_delete(buf, { force = true, unload = false })
          end
        end
      end
    },
    pre_restore_cmds = {
      -- might not be necessary, but save current harpoon data when we're about to restore a session
      function() require('harpoon'):sync() end,
    },
    post_restore_cmds = {
      function()
        -- vim.notify('calling harpoon sync after restore')
        local harpoon = require('harpoon')
        local hdata = require('harpoon.data')

        -- this is the only way i found to force harpoon to reread data from the disk rather
        -- than using what's in memory
        require('harpoon').data = hdata.Data:new(harpoon.config)
      end,
    },
  }
}


