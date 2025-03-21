#include <vector>

#include "include/function.h"

auto main(int argc, char **argv) -> int {
    if (bool const ArgcTrue = CheckArg(argc); !ArgcTrue) {
        return 1;
    }
    const char *profile = argv[1];
    const char *pathProfile = argv[2];
    // ***新方式，读取文件，没有的话去/sys搜索节点***

    // 创建FeasPath的对象feaspath
    FeasPath feaspath;
    // 读取路径配置文件
    readPathProfile(pathProfile, &feaspath);
    if (bool const MkNodeSuccessfully = AutoNode(feaspath); !MkNodeSuccessfully) {
        return 2;
    }

    //  设置游戏内中大核调速器(默认值)
    std::string middle_big_core_in_game = "performance";

    // 设置非游戏全局调速器(默认值)
    std::string gov = "schedutil";
    // 创建结构体动态数组
    std::vector<listGame> gamesaver;
    // std::vector<std::unique_ptr<listGame>> gamesaver;
    //  读取包名列表
    if (bool const ReadProfile = readProfile(profile, gamesaver, middle_big_core_in_game, gov); !ReadProfile) {
        LOG("读取文件失败，进程结束");
        return 3;
    }

    // 初始化governor和scaling_max freq
    set_gov(gov);
    recover_freq();
    LOG("运行中...");
    // 记录当前包名
    std::string now_package;
    /*
        std::thread t(matchingThread, gamesaver, std::ref(middle_big_core_in_game), std::ref(feaspath), std::ref(gov),
                      std::ref(now_package));

        t.join();
    */
    // 开始运行
    matchingThread(gamesaver, middle_big_core_in_game, feaspath, gov, now_package);
}
