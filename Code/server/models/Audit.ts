import mongoose from 'mongoose'
const { Schema } = mongoose

export enum AuditEvent {
  USER_LOGIN = 'USER_LOGIN',
  GET_USER_LIST = 'GET_USER_LIST',
  GET_DEVICE_COUNT = 'GET_DEVICE_COUNT',
  GET_AUDIT_LOGS = 'GET_AUDIT_LOGS',
  MANUAL_PUMP_CONTROL = 'MANUAL_PUMP_CONTROL'
}

const AuditSchema = new Schema(
  {
    actor: {
      type: String,
      required: [true, 'Tác nhân là bắt buộc'],
      trim: true
    },
    event: {
      type: String,
      required: [true, 'Sự kiện là bắt buộc'],
      trim: true,
      enum: Object.values(AuditEvent)
    },
    details: {
      type: String,
      required: true,
      trim: true
    }, 
    createdAt:{
        type: Date,
        default: Date.now
    }
  },
)

// đánh index để sắp xếp
AuditSchema.index({ createdAt: -1 })

const Audit = mongoose.model('Audit', AuditSchema)
export default Audit
