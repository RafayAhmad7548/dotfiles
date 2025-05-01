local function starts_with(str, prefix)
  return string.find(str, '^' .. prefix) ~= nil
end

---get the window for the right dock
---@return integer | nil window window id if exists, nil otherwise
local function get_dock_win()
  local windows = vim.api.nvim_list_wins()
  for _, win in ipairs(windows) do
    local width = vim.api.nvim_win_get_width(win)
    if width == 60 or width == 40 then
      return win
    end
  end
  return nil
end

---get the buffer which starts with prefix
---@param prefix string prefix of the name of buffer
---@return integer | nil buf buffer id if exists, nil otherwise
local function get_dock_buf(prefix)
  local buffers = vim.api.nvim_list_bufs()
  for _, buf in ipairs(buffers) do
    if vim.api.nvim_buf_is_loaded(buf) then
      local buf_name = vim.api.nvim_buf_get_name(buf)
      if starts_with(buf_name, prefix) then
        return buf
      end
    end
  end
  return nil
end

---get number of windows that are not docks i.e. right dock
---@param tabpage integer tabpage id of the tab to look in, 0 for current
---@return integer count count of non-dock windows
local function get_no_of_nondock_wins(tabpage)
  local wins = vim.api.nvim_tabpage_list_wins(tabpage)
  local count = 0
  for _, win in ipairs(wins) do
    local buf = vim.api.nvim_win_get_buf(win)
    local buf_name = vim.api.nvim_buf_get_name(buf)
    if not(starts_with(buf_name, 'term://') or starts_with(buf_name, 'oil://')) then
      count = count + 1
    end
  end
  return count
end


return {
  open_in_right_dock = function (prefix)

    -- set width accroding to terminal/oil
    local width = prefix == 'term://' and 60 or 40

    -- get dock window if exists
    local dock_win = get_dock_win()
    if dock_win ~= nil then

      local buf = vim.api.nvim_win_get_buf(dock_win)
      local buf_name = vim.api.nvim_buf_get_name(buf)
      vim.api.nvim_set_current_win(dock_win)
      vim.api.nvim_win_set_width(dock_win, width)

      if starts_with(buf_name, prefix) then
        if prefix == 'term://' then
          vim.api.nvim_feedkeys('a', 'n',  true)
        end
      else
        if prefix == 'term://' then
          vim.cmd.term()
          vim.api.nvim_feedkeys('a', 'n',  true)
        else
          vim.cmd('Oil')
        end
      end
      return
    end

    -- no dock window at this point so create new
    vim.cmd.vsplit()
    vim.api.nvim_win_set_width(0, width)

    -- get existing buf if exists
    local dock_buf = get_dock_buf(prefix)

    if dock_buf ~= nil then
      vim.api.nvim_set_current_buf(dock_buf)
      if prefix == 'term://' then
        vim.api.nvim_feedkeys('a', 'n',  true)
      end
      return
    end

    if prefix == 'term://' then
      vim.cmd.term()
      vim.api.nvim_feedkeys('a', 'n',  true)
    else
      vim.cmd('Oil')
    end
  end,

}
