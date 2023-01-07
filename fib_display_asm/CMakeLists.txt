add_executable(fib_display
        fib_display.c
        fib_display.h
        )

# pull in common dependencies
target_link_libraries(fib_display pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(fib_display)

# add url via pico_set_program_url
example_auto_set_url(fib_display)