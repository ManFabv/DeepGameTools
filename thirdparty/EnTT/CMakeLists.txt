include(FetchContent)

# EnTT - Managing library within thirdparty/EnTT
# Latest Release: v3.16.0
FetchContent_Declare(
    EnTT
    GIT_REPOSITORY https://github.com/skypjack/entt.git
    GIT_TAG v3.16.0
)

FetchContent_MakeAvailable(EnTT)
