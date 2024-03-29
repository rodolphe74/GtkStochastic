config_h = configuration_data()
config_h.set_quoted('PACKAGE_VERSION', meson.project_version())
configure_file(
  output: 'stochasticlib-config.h',
  configuration: config_h,
)
add_project_arguments([
  '-I' + meson.project_build_root(),
], language: 'cpp')


subdir('src')

