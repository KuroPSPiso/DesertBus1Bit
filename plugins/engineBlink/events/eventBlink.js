export const id = "MY_EVENT_BLINK";
export const name = "Blink";
export const groups = ["EVENT_GROUP_SCREEN"];

export const fields = [
  {
    key: "colour",
    label: "Blink Colour",
    type: "number",
    min: 0,
    max: 3,
    defaultValue: 0,
  }
];

export const compile = (input, helpers) => {
  const { _stackPushConst, _callNative, _stackPop } = helpers;
  _stackPushConst(input.colour);
  _callNative("native_blink");
  _stackPop(1);
};
