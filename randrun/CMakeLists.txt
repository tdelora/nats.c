# We need this directory to build randrun
include_directories(${PROJECT_SOURCE_DIR}/src)
# include_directories(${PROJECT_SOURCE_DIR}/examples)
include_directories(${PROJECT_SOURCE_DIR}/randrun)

add_executable(randrun randrun.c rr_logging.c rr_nats_nouns_verbs.c rr_random.c rr_nats_init_nv.c rr_nats_connect_nv.c rr_nats_pub_nv.c rr_nats_sub_nv.c)

target_include_directories(randrun PUBLIC "${PROJECT_BINARY_DIR}")
