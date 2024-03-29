gtkstochastic_sources = [
  'main.vala',
  'window.vala',
  'stochasticDrawingArea.vala',
  'application.vala',
]

gtkstochastic_deps = [
  dependency('gtk4'),
]

gnome = import('gnome')

gtkstochastic_sources += gnome.compile_resources('gtkstochastic-resources',
  'gtkstochastic.gresource.xml',
  c_name: 'gtkstochastic'
)

executable('gtkstochastic', gtkstochastic_sources,
  vala_args: '--target-glib=2.50',  dependencies: gtkstochastic_deps,
  install: true,
)
