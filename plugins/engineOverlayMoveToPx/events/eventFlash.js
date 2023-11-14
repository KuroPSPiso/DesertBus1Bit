export const id = "MY_EVENT_OVERLAY_MOVE_TO_PX";
export const name = "Overlay Move To PX";
export const groups = ["EVENT_GROUP_SCREEN"];

export const fields = [
  {
    key: "x",
    label: "FIELD_X",
    type: "number",
    min: 0,
    max: 160,
    defaultValue: 5,
  },
  {
    key: "y",
    label: "FIELD_Y",
    description: "FIELD_Y_DESC",
    type: "number",
    min: 0,
    max: 144,
    defaultValue: 0,
  },
  {
      key: "speed",
      label: "FIELD_SPEED",
      description: "FIELD_SPEED_DESC",
      type: "cameraSpeed",
      defaultValue: "0",
  },
];

export const compile = (input, helpers) => {
  const { _stackPushConst, _callNative, _stackPop } = helpers;
  _stackPushConst(input.speed);
  _stackPushConst(input.y);
  _stackPushConst(input.x);
  _callNative("native_overlay_move_to_ui");
  _stackPop(3);
};
