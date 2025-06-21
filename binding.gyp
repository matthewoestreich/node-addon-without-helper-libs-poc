{
    "targets": [
        {
            "target_name": "node-addon-without-helper-libs-poc",
            "sources": [
                "src/Greeter.cpp",
                "src/node-addon-without-helper-libs-poc.cpp",
            ],
            "include_dirs": ["src/", "third_party/z3/include"],
            "conditions": [
                [
                    "OS=='mac'",
                    {
                        "libraries": [
                            "<(module_root_dir)/third_party/z3/lib/darwin-<(target_arch)/libz3.a"
                        ]
                    },
                ],
                [
                    "OS=='linux'",
                    {
                        "libraries": [
                            "<(module_root_dir)/third_party/z3/lib/linux-<(target_arch)/libz3.a"
                        ]
                    },
                ],
                [
                    "OS=='win'",
                    {
                        "libraries": [
                            "<(module_root_dir)/third_party/z3/lib/win32-x64/libz3.lib"
                        ]
                    },
                ],
            ],
        }
    ]
}
