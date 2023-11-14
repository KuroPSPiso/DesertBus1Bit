export const id = "MY_EVENT_OVERLAY_MOVE_TO_PX_VARIABLE";
export const name = "Overlay Move To PX (with Variables)";
export const groups = ["EVENT_GROUP_SCREEN"];

export const fields = [
  {
    key: "x",
    label: "FIELD_X",
    type: "variable"
  },
  {
    key: "y",
    label: "FIELD_Y",
    description: "FIELD_Y_DESC",
    type: "variable"
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
  const { variableSetToUnionValue, _stackPushConst, _callNative, _stackPop } = helpers;
  
  const valueX = parseInt(input.x, 10);
  const valueY = parseInt(input.y, 10);

  _stackPushConst(input.speed);
  _stackPushConst(valueY);
  _stackPushConst(valueX);
  _callNative("native_overlay_move_to_ui");
  _stackPop(3);
};
