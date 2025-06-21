import path from "path";
import { fileURLToPath } from "url";
import nodeGypBuild from "node-gyp-build";

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const native = nodeGypBuild(__dirname);

export default native;
export const Greeter = native.Greeter;