[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 6
  ny = 6
  nz = 6
[]

[Variables]
  [./u]
  [../]
[]

[AuxVariables]
  [./layered_side_flux_average]
    order = CONSTANT
    family = MONOMIAL
  [../]
[]

[Functions]
  [./y]
    type = ParsedFunction
    value = y
  [../]
[]

[Kernels]
  [./diff]
    type = Diffusion
    variable = u
  [../]
[]

[BCs]
  [./bottom]
    type = DirichletBC
    variable = u
    boundary = bottom
    value = 0
  [../]
  [./top]
    type = DirichletBC
    variable = u
    boundary = top
    value = 1
  [../]
[]

[AuxBCs]
  [./lsfa]
    type = SpatialUserObjectAux
    variable = layered_side_flux_average
    boundary = top
    user_object = layered_side_flux_average
  [../]
[]

[Materials]
  [./gcm]
    type = GenericConstantMaterial
    prop_values = 2
    prop_names = diffusivity
    boundary = 'right top'
  [../]
[]

[UserObjects]
  [./layered_side_flux_average]
    type = LayeredSideFluxAverage
    direction = y
    diffusivity = diffusivity
    num_layers = 1
    variable = u
    execute_on = residual
    boundary = top
  [../]
[]

[Executioner]
  type = Steady
[]

[Output]
  output_initial = true
  exodus = true
[]

[Debug]
  show_material_props = true
[]