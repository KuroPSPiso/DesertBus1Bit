export const id = "MY_EVENT_SHOW_OVERLAY_UI";
export const name = "Show Overlay (UI)";
export const groups = ["EVENT_GROUP_SCREEN"];

export const fields = [
  {
    key: "x",
    label: "X Position",
    type: "number",
    min: 0,
    max: 160,
    defaultValue: 5,
  },
  {
    key: "y",
    label: "Y Position",
    type: "number",
    min: 0,
    max: 144,
    defaultValue: 0,
  },
  {
    key: "width",
    label: "Width",
    type: "number",
    min: 0,
    max: 160,
    defaultValue: 5,
  },
  {
    key: "height",
    label: "Height",
    type: "number",
    min: 0,
    max: 144,
    defaultValue: 0,
  },
];

export const compile = (input, helpers) => {
  const { _stackPushConst, _callNative, _stackPop } = helpers;
  _stackPushConst(input.width);
  _stackPushConst(input.y);
  _stackPushConst(input.x);
  _callNative("native_overlay_show_ui");
  _stackPop(3);
};
