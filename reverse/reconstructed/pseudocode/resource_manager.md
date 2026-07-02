# Resource Manager Pseudocode Sketch

Status: hypothesis. Evidence: DXA header, executable string table, successful extraction with key `VanillaFever11`, and resource path mapping.

```cpp
// Not original source.
void initialize_resources() {
    // Exact call site still needs decompiler confirmation.
    SetDXArchiveKeyString("VanillaFever11");

    // DxLib treats `media.dxa` as a virtual `media\\` directory.
    load_system_images(system_resource_paths);
    load_player_images(player_resource_paths);
    load_stage_images(stage_resource_paths);
    load_gallery_images(gallery_resource_paths);
    load_effect_images(effect_resource_paths);
    load_bgm(bgm_paths);
    load_se(se_paths);
    load_text_csv("media\\text\\text01.csv");
    load_text_csv("media\\text\\text02.csv");
    load_text_csv("media\\text\\text03.csv");
    load_text_csv("media\\text\\text04.csv");
}
```

Open questions:

- Whether the program calls the exported DxLib function directly or an inlined/static-linked equivalent.
- Exact resource ID ordering and ownership/lifetime model.
- Whether all resources are eagerly loaded or some are lazy-loaded by scene.
