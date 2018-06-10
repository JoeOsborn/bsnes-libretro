struct AboutWindow : Window {
  AboutWindow();

  VerticalLayout layout{this};
    Canvas canvas{&layout, Size{400, 86}, 0};
    HorizontalLayout informationLayout{&layout, Size{~0, ~0}};
      Label informationLeft{&informationLayout, Size{~0, 0}, 3};
      Label informationRight{&informationLayout, Size{~0, 0}};
};

struct Presentation : Window {
  enum : uint { RecentGames = 9, QuickStates = 9 };

  Presentation();
  auto drawIcon(uint32_t* output, uint length, uint width, uint height) -> void;
  auto clearViewport() -> void;
  auto resizeViewport() -> void;
  auto resizeWindow() -> void;
  auto toggleFullscreenMode() -> void;
  auto clearRecentGames() -> void;
  auto updateRecentGames() -> void;
  auto addRecentGame(string location) -> void;
  auto updateShaders() -> void;

  MenuBar menuBar{this};
    Menu systemMenu{&menuBar};
      MenuItem loadGame{&systemMenu};
      Menu loadRecentGame{&systemMenu};
      MenuItem resetSystem{&systemMenu};
      MenuItem unloadGame{&systemMenu};
      MenuSeparator portSeparator{&systemMenu};
      Menu controllerPort1{&systemMenu};
      Menu controllerPort2{&systemMenu};
      Menu expansionPort{&systemMenu};
      MenuSeparator quitSeparator{&systemMenu};
      MenuItem quit{&systemMenu};
    Menu settingsMenu{&menuBar};
      Menu viewMenu{&settingsMenu};
        MenuItem smallView{&viewMenu};
        MenuItem mediumView{&viewMenu};
        MenuItem largeView{&viewMenu};
        MenuSeparator viewSeparator{&viewMenu};
        MenuCheckItem aspectCorrection{&viewMenu};
        MenuCheckItem overscanCropping{&viewMenu};
        MenuCheckItem integralScaling{&viewMenu};
        MenuCheckItem blurEmulation{&viewMenu};
        MenuCheckItem colorEmulation{&viewMenu};
      Menu shaderMenu{&settingsMenu};
      MenuCheckItem muteAudio{&settingsMenu};
      MenuCheckItem showStatusBar{&settingsMenu};
      MenuSeparator settingsSeparator{&settingsMenu};
      MenuItem videoSettings{&settingsMenu};
      MenuItem audioSettings{&settingsMenu};
      MenuItem inputSettings{&settingsMenu};
      MenuItem hotkeySettings{&settingsMenu};
      MenuItem pathSettings{&settingsMenu};
      MenuItem advancedSettings{&settingsMenu};
    Menu toolsMenu{&menuBar};
      Menu saveState{&toolsMenu};
      Menu loadState{&toolsMenu};
      MenuCheckItem pauseEmulation{&toolsMenu};
      MenuSeparator toolsSeparator{&toolsMenu};
      MenuItem cheatEditor{&toolsMenu};
      MenuItem stateManager{&toolsMenu};
    Menu helpMenu{&menuBar};
      MenuItem about{&helpMenu};

  FixedLayout layout{this};
    Viewport viewport{&layout, Geometry{0, 0, 1, 1}};

  StatusBar statusBar{this};
};

extern unique_pointer<AboutWindow> aboutWindow;
extern unique_pointer<Presentation> presentation;
