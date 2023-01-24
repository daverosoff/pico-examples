add_library(fib
        fib.c
        )

# allow exporting from this library even though it is marked EXECUTABLE
#set_property(TARGET PROPERTY ENABLE_EXPORTS TRUE)

# pull in common dependencies
target_link_libraries(fib pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(fib)

# add url via pico_set_program_url
example_auto_set_url(fib)
