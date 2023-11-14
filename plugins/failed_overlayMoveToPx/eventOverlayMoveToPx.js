export const id = "JD_OVERLAY_MOVE_TO_PX"
export const name = "Overlay Move To PX"
export const groups = ["EVENT_GROUP_SCREEN"];

export const fields = [
    {
        type: "group",
        fields: [
            {
                key: "x",
                label: l10n("FIELD_X"),
                description: l10n("FIELD_X_DESC"),
                type: "number",
                min: 0,
                max: 160,
                defaultValue: 0,
                width: "50%",
            },
            {
                key: "y",
                label: l10n("FIELD_Y"),
                description: l10n("FIELD_Y_DESC"),
                type: "number",
                min: 0,
                max: 144,
                defaultValue: 0,
                width: "50%",
            },
        ],
    },
    {
        key: "speed",
        label: l10n("FIELD_SPEED"),
        description: l10n("FIELD_SPEED_DESC"),
        type: "cameraSpeed",
        defaultValue: "0",
    },
];

export const compile = (input, helpers) => {
    const { variableSetToValue, _callNative, _stackPushConst, _stackPop } = helpers;
    const { x, y, speed } = input;
    variableSetToValue( x, value);
    variableSetToValue( y, value);
}