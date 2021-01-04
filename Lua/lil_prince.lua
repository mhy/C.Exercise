local function ship_is_within_the_range(star, ship)
  -- print('===')
  -- print('ship is ' .. ship.x .. ', ' .. ship.y)
  -- print('star is ' .. star.x .. ', ' .. star.y)
  -- print('l : ' .. (ship.x - star.x) ^ 2 + (ship.y - star.y) ^ 2 .. ' and r : ' .. (star.r) * 2)
  -- print('===')
  return (ship.x - star.x) ^ 2 + (ship.y - star.y) ^ 2 <= (star.r) ^ 2
end

local ships_of_all_iterations = {}
local stars_of_all_iterations = {}

local numberOfIteration = io.read("*n")
for i = 1, numberOfIteration, 1 do
  local ships = {}
  local stars = {}
  local ship1_x, ship1_y, ship2_x, ship2_y = io.read("*n", "*n", "*n", "*n")
  table.insert(ships, {x = ship1_x, y = ship1_y})
  table.insert(ships, {x = ship2_x, y = ship2_y})

  local numberOfStars = io.read("*n")
  for k = 1, numberOfStars, 1 do
    local star_x, star_y, star_r = io.read("*n", "*n", "*n")
    table.insert(stars, {x = star_x, y = star_y, r = star_r})
  end

  table.insert(ships_of_all_iterations, ships)
  table.insert(stars_of_all_iterations, stars)
end

local final_result = {}
for i = 1, numberOfIteration, 1 do
  local ship_a = table.remove(ships_of_all_iterations[i], 1)
  local ship_b = table.remove(ships_of_all_iterations[i], 1)

  local result = 0
  -- print('-----')
  for j, star in ipairs(stars_of_all_iterations[i]) do
    -- print('ship a is ' .. tostring(ship_is_within_the_range(star, ship_a)))
    -- print('ship b is ' .. tostring(ship_is_within_the_range(star, ship_b)))
    if ship_is_within_the_range(star, ship_a) ~= ship_is_within_the_range(star, ship_b) then
      result = result + 1
    end
  end
  table.insert(final_result, result)
end

for i, v in ipairs(final_result) do
  print(v)
end