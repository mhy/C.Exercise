function detect(location_one, location_two)
  local distance_between_two = math.sqrt((location_one.x - location_two.x) ^ 2 + (location_one.y - location_two.y) ^ 2)
  local range_radar_positive = location_one.r + location_two.r
  local range_radar_negative = math.abs(location_one.r - location_two.r)

  local result
  if distance_between_two == 0 then
    if location_one.r == location_two.r then
      result = -1
    else
      result = 0
    end
  elseif distance_between_two > range_radar_positive or distance_between_two < range_radar_negative then
    result = 0
  elseif distance_between_two == range_radar_positive or distance_between_two == range_radar_negative then
    result = 1
  elseif distance_between_two < range_radar_positive and distance_between_two > range_radar_negative then
    result = 2
  end

  return result
end

local numberOfIteration = io.read("*n")
local cases = {}
for i = 1, numberOfIteration, 1 do
  local try = {}
  for j = 1, 6, 1 do
    table.insert(try, io.read("*n"))
  end
  table.insert(cases, try)
end

for i = 1, numberOfIteration, 1 do
  local location_a = {x = cases[i][1], y = cases[i][2], r = cases[i][3]}
  local location_b = {x = cases[i][4], y = cases[i][5], r = cases[i][6]}
  print(detect(location_a, location_b))
end
