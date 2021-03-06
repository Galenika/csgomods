import React from "react";
import { Menu as CMenu } from "@components";
import { ActiveTab } from "@utils";
import { AimbotIcon, ConfigsIcon, MiscellaneousIcon, SkinchangerIcon, VisualsIcon } from "./images";

export type MenuProps = {
  activeTab: ActiveTab;
  setActiveTab: React.Dispatch<React.SetStateAction<ActiveTab>>;
};
export const Menu: React.FC<MenuProps> = ({ activeTab, setActiveTab }) => {
  return (
    <CMenu
      tabs={[
        {
          title: "Visuals",
          subtitle: "Glow ESP, Chams",
          iconUrl: VisualsIcon,
          active: activeTab === ActiveTab.TAB_VISUALS,
          onClick: () => setActiveTab(ActiveTab.TAB_VISUALS),
        },
        {
          title: "Aimbot",
          subtitle: "Legit, Trigger, Weapon settings, Recoil control",
          iconUrl: AimbotIcon,
          active: activeTab === ActiveTab.TAB_AIMBOT,
          onClick: () => setActiveTab(ActiveTab.TAB_AIMBOT),
        },
        {
          title: "Skinchanger",
          subtitle: "Skins, knives",
          iconUrl: SkinchangerIcon,
          active: activeTab === ActiveTab.TAB_SKINCHANGER,
          onClick: () => setActiveTab(ActiveTab.TAB_SKINCHANGER),
        },
        {
          title: "Miscellaneous",
          subtitle: "Bhop, Auto pistols, Auto accept, Anti-flash",
          iconUrl: MiscellaneousIcon,
          active: activeTab === ActiveTab.TAB_MISC,
          onClick: () => setActiveTab(ActiveTab.TAB_MISC),
        },
        {
          title: "Configs",
          subtitle: "Configs list",
          iconUrl: ConfigsIcon,
          active: activeTab === ActiveTab.TAB_CONFIG,
          onClick: () => setActiveTab(ActiveTab.TAB_CONFIG),
        },
      ]}
    />
  );
};
