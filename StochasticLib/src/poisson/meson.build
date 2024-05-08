#~ project('static lib', ['cpp', 'c'])

# Create command line program
add_project_arguments(
	['-Wno-unused-variable'],
	['-Wno-unused-function'],
	['-Wno-sign-compare'],
	['-Wno-unknown-pragmas'],
	['-Wno-unused-but-set-variable'],
	['-Wno-type-limits'],
	['-Wno-unused-parameter'],
	language : ['cpp', 'c'])

subdir('argparse')
subdir('mathc')
subdir('delaunator')

pkg_deps = [
  dependency(['cairo']),
]

argparseincdir = include_directories('argparse')
mathcincdir = include_directories('mathc')
delaunatorincdir = include_directories('delaunator')
executable(	'stochastic', ['sd.cpp', 'cairoUtils.cpp', 'ImageUtils.cpp', 'raster.cpp', 'vertex.cpp', 'voronoiUtils.cpp'],
			include_directories:[argparseincdir, mathcincdir, delaunatorincdir],
			dependencies:pkg_deps,
			link_with: [delaunatorlib, mathclib, argparselib],
)


# Create shared lib
stochasticlib_sources = [
  'stochasticLib.cpp', 'ImageUtils.cpp', 'raster.cpp', 'mathc/mathc.cpp'
]

stochasticlib_headers = [
  'stochasticLib.h'
]

stochasticlib_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('cairo'),
]

stochasticlib_lib = shared_library('stochasticlib',
  stochasticlib_sources,
  dependencies: stochasticlib_deps,
  include_directories:[argparseincdir, mathcincdir, delaunatorincdir],
  install: true,
)



#~ pkg = import('pkgconfig')
#~ pkg.generate(
#~   description: 'A shared library for ...',
#~     libraries: stochasticlib_lib,
#~          name: 'stochasticlib',
#~      filebase: 'stochasticlib-' + api_version,
#~       version: meson.project_version(),
#~       subdirs: 'stochasticlib',
#~      requires: 'glib-2.0',
#~   install_dir: join_paths(get_option('libdir'), 'pkgconfig')
#~ )


# Create vala program linked with above shared lib
# valac --vapidir . --pkg libstochastic testlib.vala -X ../builddir/src/libstochasticlib-0.1.so
vala_sources = [
  'testlib.vala',
]

vapi_dir = meson.current_source_dir()

vala_deps = [
  dependency(['gtk4']),
  meson.get_compiler('vala').find_library('libstochastic', dirs: vapi_dir),
]

# gnome = import('gnome')

executable('testlib', vala_sources,
  vala_args: ['--target-glib=2.50'],  
  dependencies: vala_deps,
  link_with: stochasticlib_lib,
  install: true,
)
