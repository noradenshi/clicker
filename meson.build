project('clicker', 'c',
  default_options: [
    'prefix=/home/noradenshi/Projects/clicker',
    'c_std=c2x'
  ]
)

cc = meson.get_compiler('c')

deps = [ cc.find_library('raylib') ]

sources = files(
  'src/main.c',
  'src/cookie.c',
  'src/particles.c'
) 

executable('exe', sources,
  include_directories: ['include'],
  dependencies: deps,
  install: true)
