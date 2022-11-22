const wasmAddon = require('../index')
const assert = require('assert')

assert(wasmAddon.track, "Expected function undefined")
assert(wasmAddon.equal, "Expected function undefined")

assert.strictEqual(null, wasmAddon.track(), "Unexpected value")
assert.strictEqual(null, wasmAddon.equal(), "Unexpected value")
