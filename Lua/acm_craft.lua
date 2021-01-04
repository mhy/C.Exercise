-- cost_of_buildings = { { cost_of_this_building =  , required_cost_before_this_building = }, ... }
local function populate_cost_of_buildings(number_of_buildings)
  local cost_of_buildings = {}
  for i = 1, number_of_buildings, 1 do
    local cost = io.read("*n")
    table.insert(cost_of_buildings, {cost_of_this_building = cost, required_cost_before_this_building = 0})
  end
  return cost_of_buildings
end

-- recipes = { { dest1_from_building_1, dest2_from_building_1 }, { }, { dest1_from_building_3 }, { false } ... }
-- in case of building_2, it does not have any destination
-- in case of building_4, it has already been checked by the algorithm ; no need to check dependency
local function populate_recipes(number_of_buildings, number_of_recipes)
  local recipes = {}

  for i = 1, number_of_buildings do
    table.insert(recipes, {})
  end

  for i = 1, number_of_recipes, 1 do
    local from, to = io.read("*n", "*n")
    table.insert(recipes[from], to)
  end
  return recipes
end

already_checked = false
no_need_to_check_dependency = true
local function buildings_with_no_dependencies(recipes)
  local buildings_with_dependencies = {}
  for building, dependencies in ipairs(recipes) do
    for _, building_in_dependency in ipairs(dependencies) do
      if building_in_dependency == already_checked then
        buildings_with_dependencies[building] = no_need_to_check_dependency
      else
        buildings_with_dependencies[building_in_dependency] = true
      end
    end
  end

  local buildings_with_no_dependencies = {}
  for i = 1, #recipes do
    if buildings_with_dependencies[i] == nil then
      table.insert(buildings_with_no_dependencies, i)
    end
  end

  return buildings_with_no_dependencies
end

local function optimized_build_tree(cost_of_buildings, recipes, goal)
  local goal_reached = false
  repeat
    local bwnd_s = buildings_with_no_dependencies(recipes)
    for _, bwnd in ipairs(bwnd_s) do
      for _, building_dependent_on_bwnd in ipairs(recipes[bwnd]) do
        local required_cost_of_bwnd =
          cost_of_buildings[bwnd].cost_of_this_building + cost_of_buildings[bwnd].required_cost_before_this_building
        local currently_required_cost = cost_of_buildings[building_dependent_on_bwnd].required_cost_before_this_building

        if required_cost_of_bwnd > currently_required_cost then
          cost_of_buildings[building_dependent_on_bwnd].required_cost_before_this_building = required_cost_of_bwnd
        end
      end
      recipes[bwnd] = {already_checked}
      if bwnd == goal then
        goal_reached = true
        break
      end
    end
  until (goal_reached)

  return cost_of_buildings[goal].cost_of_this_building + cost_of_buildings[goal].required_cost_before_this_building
end

local function game(round)
  local results = {}
  for i = 1, round do
    local number_of_buildings, number_of_recipes = io.read("*n", "*n")

    local cost_of_buildings = populate_cost_of_buildings(number_of_buildings)
    local recipes = populate_recipes(number_of_buildings, number_of_recipes)

    local goal = io.read("*n")
    table.insert(results, optimized_build_tree(cost_of_buildings, recipes, goal))
  end
  return results
end

local number_of_rounds = io.read("*n")
local results = game(number_of_rounds)
for _, result in ipairs(results) do
  print(result)
end
